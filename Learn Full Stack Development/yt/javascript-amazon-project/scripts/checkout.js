import { cart, editCartQuantity, getCartQuantity, getCartQuantityById, removeFromCart, saveLocalStorage, updateCartQuantity, updateCartQuantityById } from "../data/cart.js";
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
                    Quantity: <span class="quantity-label quantity-label-${matchingProduct.id}">${cartItem.quantity}</span>
                  </span>
                  <span class="update-quantity-link update-quantity-link-${matchingProduct.id} link-primary" data-product-id="${matchingProduct.id}">
                    Update
                  </span>
                  <input class="quantity-input quantity-input-${matchingProduct.id}" type="number">
                  <span class="save-quantity-link save-quantity-link-${matchingProduct.id} link-primary" data-product-id="${matchingProduct.id}"">Save</span>
                  <span class="delete-quantity-link link-primary" data-product-id="${matchingProduct.id}">
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
document.querySelectorAll('.update-quantity-link').forEach((update) => {
  update.addEventListener('click', (event) => {
    const productId = update.getAttribute('data-product-id');
    const inputElement = document.querySelector(`.quantity-input-${productId}`);
    const saveElement = document.querySelector(`.save-quantity-link-${productId}`);
    const currentQuantity = getCartQuantityById(productId);
    // hide update link
    update.classList.toggle('is-editing-quantity-hide');
    // show input
    inputElement.classList.toggle('is-editing-quantity-show');
    // show save link
    saveElement.classList.toggle('is-editing-quantity-show');
    // update current quantity inside input
    inputElement.value = currentQuantity;

  })
})

// Add event listeners to the save quantity links
document.querySelectorAll('.save-quantity-link').forEach((save) => {
  const productId = save.getAttribute('data-product-id');
  save.addEventListener('click', (event) => {
    const updateElement = document.querySelector(`.update-quantity-link-${productId}`);
    const inputElement = document.querySelector(`.quantity-input-${productId}`);
    const quantity = parseInt(inputElement.value);
    // show update link
    updateElement.classList.toggle('is-editing-quantity-hide');
    // hide input
    inputElement.classList.toggle('is-editing-quantity-show');
    // hide save link
    save.classList.toggle('is-editing-quantity-show');
    // call editCartQuantity
    editCartQuantity(productId, quantity);
    // update quantity labels
    updateCartQuantityById(productId, `.quantity-label-${productId}`);
    updateCartQuantity('.js-return-to-home-link', ' items');
  });
})


