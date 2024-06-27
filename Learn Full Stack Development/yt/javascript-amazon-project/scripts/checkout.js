import { cart, getCartQuantity, removeFromCart, saveLocalStorage, updateCartQuantity } from "../data/cart.js";
import { products } from "../data/products.js";
import { formatMoney } from "../utils/money.js";

let orderSummaryHTML = '';

saveLocalStorage();
cart.forEach((cartItem, index) => {

  const returnHomeElement = document.querySelector('.js-return-to-home-link');
  returnHomeElement.textContent = ` ${getCartQuantity()} items`;

  let productId = cartItem.productId;
  let matchingProduct = products.find((product) => {
    return product.id === productId;
  });

  orderSummaryHTML += `
    <div class="cart-item-container js-cart-item-container-${matchingProduct.id}">
            <div class="delivery-date">
              Delivery date: Tuesday, June 21
            </div>

            <div class="cart-item-details-grid">
              <img class="product-image"
                src=${matchingProduct.image}>

              <div class="cart-item-details">
                <div class="product-name">
                ${matchingProduct.name}
                </div>
                <div class="product-price">
                  $${formatMoney(matchingProduct.priceCents)}
                </div>
                <div class="product-quantity">
                  <span>
                    Quantity: <span class="quantity-label">${cartItem.quantity}</span>
                  </span>
                  <span class="update-quantity-link link-primary" data-product-id="${matchingProduct.id}">
                    Update
                  </span>
                  <span class="delete-quantity-link link-primary" data-product-id=${matchingProduct.id}>
                    Delete
                  </span>
                </div>
              </div>

              <div class="delivery-options">
                <div class="delivery-options-title">
                  Choose a delivery option:
                </div>
                <div class="delivery-option">
                  <input type="radio" checked
                    class="delivery-option-input"
                    name="delivery-option-${matchingProduct.id}">
                  <div>
                    <div class="delivery-option-date">
                      Tuesday, June 21
                    </div>
                    <div class="delivery-option-price">
                      FREE Shipping
                    </div>
                  </div>
                </div>
                <div class="delivery-option">
                  <input type="radio"
                    class="delivery-option-input"
                    name="delivery-option-${matchingProduct.id}">
                  <div>
                    <div class="delivery-option-date">
                      Wednesday, June 15
                    </div>
                    <div class="delivery-option-price">
                      $4.99 - Shipping
                    </div>
                  </div>
                </div>
                <div class="delivery-option">
                  <input type="radio"
                    class="delivery-option-input"
                    name="delivery-option-${matchingProduct.id}">
                  <div>
                    <div class="delivery-option-date">
                      Monday, June 13
                    </div>
                    <div class="delivery-option-price">
                      $9.99 - Shipping
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
  `;
});
// Add the generated HTML to the order-summary
document.querySelector('.order-summary').innerHTML = orderSummaryHTML;

// Add event listeners to the delete quantity links
document.querySelectorAll('.delete-quantity-link').forEach((button) => {
  button.addEventListener('click', (event) => {
    const productId = button.getAttribute('data-product-id');
    removeFromCart(productId);
    document.querySelector(`.js-cart-item-container-${productId}`).remove();
    updateCartQuantity('.js-return-to-home-link', ' items');
  });
})

// Add event listeners to the update quantity links
document.querySelectorAll('.update-quantity-link').forEach((link) => {
  link.addEventListener('click', (event) => {
    const productId = link.getAttribute('data-product-id');
    console.log('update quantity for product id:', productId);
  })
})

