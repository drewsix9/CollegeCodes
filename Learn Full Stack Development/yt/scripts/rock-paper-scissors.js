
// get the scoreboard element from local storage
let gameScore = JSON.parse(localStorage.getItem('gameScore')) || {
  wins: 0,
  losses: 0,
  ties: 0
};

// display the scoreboard
document.querySelector('.js-scoreboard').textContent = `Wins: ${gameScore.wins}, Losses: ${gameScore.losses}, Ties: ${gameScore.ties}`

const pressButton = (playerChoice) => {
  const choices = ['rock', 'paper', 'scissors'];
  const computerChoice = choices[Math.floor(Math.random() * choices.length)];

  // alert(`Player: ${playerChoice}, Computer: ${computerChoice}\n You ${playerChoice === computerChoice ? 'tied' : playerChoice === 'rock' && computerChoice === 'scissors' || playerChoice === 'paper' && computerChoice === 'rock' || playerChoice === 'scissors' && computerChoice === 'paper' ? 'won' : 'lost'}`);

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

const resetScore = () => {
  gameScore = {
    wins: 0,
    losses: 0,
    ties: 0
  };
  document.querySelector('.js-scoreboard').textContent = `Wins: ${gameScore.wins}, Losses: ${gameScore.losses}, Ties: ${gameScore.ties}`;
  localStorage.setItem('gameScore', JSON.stringify(gameScore));
}