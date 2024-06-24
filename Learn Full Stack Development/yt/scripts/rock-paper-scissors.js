
// add event listeners to the buttons
document.querySelector('.rock-button').addEventListener('click', () => pressButton('rock'))
document.querySelector('.paper-button').addEventListener('click', () => pressButton('paper'))
document.querySelector('.scissors-button').addEventListener('click', () => pressButton('scissors'))
document.querySelector('.reset-button').addEventListener('click', resetScore)
document.querySelector('.auto-play-button').addEventListener('click', autoPlay)


// get the scoreboard element from local storage
let gameScore = JSON.parse(localStorage.getItem('gameScore')) || {
  wins: 0,
  losses: 0,
  ties: 0
};

// display the scoreboard
document.querySelector('.js-scoreboard').textContent = `Wins: ${gameScore.wins}, Losses: ${gameScore.losses}, Ties: ${gameScore.ties}`

function pickRandom() {
  const choices = ['rock', 'paper', 'scissors'];
  return choices[Math.floor(Math.random() * choices.length)];
}

function pressButton(playerChoice) {

  const computerChoice = pickRandom();

  let result = '';

  if (playerChoice === computerChoice) {
    result = 'TIE';
    gameScore.ties++;
  } else if (
    (playerChoice === 'rock' && computerChoice === 'scissors') ||
    (playerChoice === 'paper' && computerChoice === 'rock') ||
    (playerChoice === 'scissors' && computerChoice === 'paper')
  ) {
    result = 'WIN';
    gameScore.wins++;
  } else {
    result = 'LOSE';
    gameScore.losses++;
  }
  document.querySelector('.js-result').textContent = `You ${result}`;
  document.querySelector('.js-resulting-moves').innerHTML = `
  You <img class="js-resulting-moves-icon"src="images/${playerChoice}.png">
  <img class="js-resulting-moves-icon"src="images/${computerChoice}.png"> Computer
  `;
  document.querySelector('.js-scoreboard').textContent = `Wins: ${gameScore.wins}, Losses: ${gameScore.losses}, Ties: ${gameScore.ties}`;

  // save the scoreboard to local storage
  localStorage.setItem('gameScore', JSON.stringify(gameScore));
};

function resetScore() {
  gameScore = {
    wins: 0,
    losses: 0,
    ties: 0
  };
  document.querySelector('.js-scoreboard').textContent = `Wins: ${gameScore.wins}, Losses: ${gameScore.losses}, Ties: ${gameScore.ties}`;
  localStorage.setItem('gameScore', JSON.stringify(gameScore));
}

let autoPlayIntervalID;
let isAutoPlaying = false;

function autoPlay() {
  if (!isAutoPlaying) {
    autoPlayIntervalID = setInterval(() => {
      const playerChoice = pickRandom();
      pressButton(playerChoice);
    }, 500);
    isAutoPlaying = true;
  } else {
    clearInterval(autoPlayIntervalID);
    isAutoPlaying = false;
  }
}