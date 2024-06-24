let todoList = [
  {
    name: "Learn JavaScript",
    dueDate: "2021-09-01",
  },
  {
    name: "Learn React",
    dueDate: "2021-09-02",
  },
  {
    name: "Learn Node",
    dueDate: "2021-09-03",
  },
  {
    name: "Learn Express",
    dueDate: "2021-09-04",
  },
  {
    name: "Learn MongoDB",
    dueDate: "2021-09-05",
  },
  {
    name: "Learn Mongoose",
    dueDate: "2021-09-06",
  },
  {
    name: "Learn Redux",
    dueDate: "2021-09-07",
  },
  {
    name: "Learn Redux Thunk",
    dueDate: "2021-09-08",
  },

];

// add event listeners
document.querySelector('.add-button').addEventListener('click', addTodoItem);
document.addEventListener("DOMContentLoaded", function () {
  renderTodoList();
});


function renderTodoList() {
  let todoListHTMLElement = "";
  console.clear();
  todoList.forEach((todoItem, index) => {
    const { name, dueDate } = todoItem;
    console.log(todoList[index]);
    todoListHTMLElement +=
      `
    <div class="todo-item">${name}</div> 
    <div class="todo-item">${dueDate}</div> 
    <button class="delete-todo">Delete</button>
    `;
  });
  // add the todo list to the html
  document.querySelector(".todo-list").innerHTML = todoListHTMLElement;
  // add event listeners to the delete buttons
  document.querySelectorAll('.delete-todo').forEach((button, index) => {
    button.addEventListener('click', () => { deleteTodoItem(index) });
  })
}

function deleteTodoItem(index) {
  todoList.splice(index, 1);
  renderTodoList();
}

function addTodoItem() {
  const nameInputElemet = document.querySelector(".input-name");
  const dateInputElemet = document.querySelector(".input-date");
  const name = nameInputElemet.value;
  const dueDate = dateInputElemet.value;
  todoList.push({ name, dueDate });
  nameInputElemet.value = "";
  dateInputElemet.value = "";
  renderTodoList();
}