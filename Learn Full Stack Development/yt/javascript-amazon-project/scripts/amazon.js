import { addToCart, cart, updateCartQuantity } from '../data/cart.js';
import { products } from '../data/products.js';
let productsHTML = "";

products.forEach((product) => {
  productsHTML += `
  <div class="product-container">
          <div class="product-image-container">
            <img class="product-image"
              src="${product.image}">
          </div>

          <div class="product-name limit-text-to-2-lines">
            ${product.name}
          </div>

          <div class="product-rating-container">
            <img class="product-rating-stars"
              src="images/ratings/rating-${product.rating.stars * 10}.png">
            <div class="product-rating-count link-primary">
              ${product.rating.count} 
            </div>
          </div>

          <div class="product-price">
            $${(product.priceCents / 100).toFixed(2)}
          </div>

          <div class="product-quantity-container">
            <select>
              <option selected value="1">1</option>
              <option value="2">2</option>
              <option value="3">3</option>
              <option value="4">4</option>
              <option value="5">5</option>
              <option value="6">6</option>
              <option value="8">8</option>
              <option value="7">7</option>
              <option value="9">9</option>
              <option value="10">10</option>
            </select>
          </div>

          <div class="product-spacer"></div>

          <div class="added-to-cart added-to-cart-${product.id}">
            <img src="images/icons/checkmark.png">
            Added
          </div>
          <button class="add-to-cart-button button-primary js-add-to-card" data-product-id="${product.id}">
            Add to Cart
          </button>
        </div>`;
});

// Add the generated HTML to the products-grid
document.querySelector('.products-grid').innerHTML = productsHTML;

document.addEventListener('DOMContentLoaded', () => {
  updateCartQuantity('.cart-quantity');
});

// Add the event listener to the add to cart button
document.querySelectorAll('.js-add-to-card').forEach((button, index) => {
  button.addEventListener('click', () => {
    const productId = button.dataset.productId;
    const quantitySelectorElement = document.querySelectorAll('.product-quantity-container select')[index];
    const quantity = parseInt(quantitySelectorElement.value);

    addToCart(productId, quantity);

    updateCartQuantity('.cart-quantity');

    // show hint added to cart
    showHintAddedToCart(productId);

    // Reset the quantity selector to 1
    quantitySelectorElement.value = 1;
    console.log(cart);
  })
})

function showHintAddedToCart(productId) {
  const element = document.querySelector(`.added-to-cart-${productId}`);

  element.style.opacity = '1';
  // Ensure any existing timeout is cleared before setting a new one
  if (element.timeoutId) {
    clearTimeout(element.timeoutId);
  }

  // Set timeout and capture its ID
  element.timeoutId = setTimeout(() => {
    element.style.opacity = '0';
    element.style.transition = 'opacity 0.5s';
    // Clear the timeoutId after it executes
    delete element.timeoutId;
  }, 2000);
}





