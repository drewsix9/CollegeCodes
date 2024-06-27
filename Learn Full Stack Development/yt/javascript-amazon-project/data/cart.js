export let cart = JSON.parse(localStorage.getItem('cart')) || [];
// export let cart = [
//   // {
//   //   productId: "15b6fc6f-327a-4ec4-896f-486349e85a3d",
//   //   quantity: 2
//   // },
//   // {
//   //   productId: "e43638ce-6aa0-4b85-b27f-e1d07eb678c6",
//   //   quantity: 1
//   // }
// ]

export function saveLocalStorage() {
  console.info('Saving cart to local storage\n cart:', cart)
  const cartString = JSON.stringify(cart);
  localStorage.setItem('cart', cartString);
}

export function addToCart(productId, quantity) {
  let matchingProduct = false;
  cart.forEach((cartItem) => {
    if (cartItem.productId === productId) {
      matchingProduct = true;
      cartItem.quantity += quantity;
    }
  });
  if (!matchingProduct) {
    cart.push({
      productId,
      quantity
    });
  }
  saveLocalStorage();
}

export function removeFromCart(productId) {
  cart = cart.filter((cartItem) => {
    return cartItem.productId !== productId;
  });
  saveLocalStorage();
}

export function editCartQuantity(productId, quantity) {
  cart.forEach((cartItem) => {
    if (cartItem.productId === productId) {
      cartItem.quantity = quantity;
    }
  })
  saveLocalStorage();
}

export function getCartQuantity() {
  let cartQuantity = 0;
  cart.forEach((item) => {
    cartQuantity += item.quantity;
  }); '.cart-quantity'
  return cartQuantity;
}

export function getCartQuantityById(productId) {
  return cart.find((item) => {
    return item.productId === productId;
  }).quantity;
}

export function updateCartQuantity(className, suffix = '') {
  const element = document.querySelector(className);
  element.textContent = getCartQuantity() + suffix;
  console.log(element.textContent);
}

export function updateCartQuantityById(productId, className, suffix = '') {
  const element = document.querySelector(className);
  element.textContent = getCartQuantityById(productId) + suffix;
  console.log(element.textContent);
}