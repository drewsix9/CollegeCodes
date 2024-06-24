export let cart = new Map();

export function addToCart(productId, quantity) {
  if (cart.has(productId)) {
    // If the item is already in the cart, update the quantity
    let item = cart.get(productId);
    item.quantity += quantity;
    cart.set(productId, item);
  } else {
    // If the item is not in the cart, add it
    cart.set(productId, { productId, quantity });
  }
}

export function updateCartQuantity() {
  let cartQuantity = 0;
  cart.forEach((item) => {
    cartQuantity += item.quantity;
  });
  document.querySelector('.cart-quantity').textContent = cartQuantity;
}