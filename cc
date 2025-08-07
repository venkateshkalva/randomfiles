const input = document.getElementById('decimalInput');
const error = document.getElementById('errorMsg');

input.addEventListener('input', () => {
  const val = input.value;

  // Check if it's a valid number
  const num = parseFloat(val);

  // Match up to 6 decimal places
  const validDecimal = /^\d{1,3}(\.\d{0,6})?$/;

  if (num > 100 || !validDecimal.test(val)) {
    error.textContent = 'Max: 100.000000 and only 6 decimal places allowed';
    // Trim invalid part
    input.value = val.slice(0, -1);
  } else {
    error.textContent = '';
  }
});
