<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Owner Taxpayer ID - Clear Button Placement</title>
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  body { font-family: Arial, sans-serif; background: #f4f4f4; padding: 40px; }

  .container {
    background: white;
    border: 1px solid #ccc;
    padding: 30px;
    max-width: 900px;
    margin: auto;
  }

  .form-row {
    display: flex;
    gap: 16px;
    margin-bottom: 24px;
    align-items: flex-start;
  }

  .field-group {
    flex: 1;
  }

  label.field-label {
    display: block;
    font-weight: bold;
    margin-bottom: 8px;
    font-size: 14px;
  }

  input[type="text"], select {
    width: 100%;
    padding: 10px 12px;
    border: 1px solid #aaa;
    border-radius: 3px;
    font-size: 14px;
    color: #333;
    background: white;
  }

  select {
    appearance: none;
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='12' height='8' viewBox='0 0 12 8'%3E%3Cpath d='M1 1l5 5 5-5' stroke='%23666' stroke-width='1.5' fill='none'/%3E%3C/svg%3E");
    background-repeat: no-repeat;
    background-position: right 12px center;
    padding-right: 32px;
  }

  .taxpayer-block {
    background: #f9f9ff;
    border: 1.5px solid #c8d8f8;
    border-radius: 6px;
    padding: 18px 20px;
    margin-bottom: 24px;
  }

  .taxpayer-header {
    display: flex;
    align-items: center;
    justify-content: space-between;
    margin-bottom: 14px;
  }

  .taxpayer-header .field-label {
    margin: 0;
    font-size: 14px;
  }

  .btn-clear {
    background: white;
    border: 1.5px solid #2060c0;
    color: #2060c0;
    padding: 5px 14px;
    border-radius: 4px;
    font-size: 13px;
    font-weight: bold;
    cursor: pointer;
    transition: background 0.15s;
    position: relative;
  }

  .btn-clear:hover { background: #eef4ff; }

  .btn-clear .tooltip {
    display: none;
    position: absolute;
    bottom: calc(100% + 8px);
    right: 0;
    background: #1a3a6a;
    color: white;
    font-size: 11px;
    font-weight: normal;
    padding: 5px 10px;
    border-radius: 4px;
    white-space: nowrap;
    pointer-events: none;
  }

  .btn-clear .tooltip::after {
    content: '';
    position: absolute;
    top: 100%;
    right: 14px;
    border: 5px solid transparent;
    border-top-color: #1a3a6a;
  }

  .btn-clear:hover .tooltip { display: block; }

  .radio-group {
    display: flex;
    align-items: center;
    gap: 24px;
    flex-wrap: wrap;
  }

  .radio-option {
    display: flex;
    align-items: center;
    gap: 6px;
    font-size: 14px;
    cursor: pointer;
  }

  input[type="radio"] {
    width: 15px;
    height: 15px;
    cursor: pointer;
    accent-color: #2060c0;
  }

  .fields-row {
    display: flex;
    gap: 16px;
    margin-top: 14px;
  }

  .note-box {
    background: #fff8f0;
    border: 1px solid #f0c080;
    padding: 12px 16px;
    border-radius: 3px;
    font-size: 13px;
    color: #333;
    margin-bottom: 24px;
  }

  .note-box strong { color: #c0392b; }
  .note-box .keyword { color: #2060c0; font-weight: bold; }

  .footer-row {
    display: flex;
    justify-content: space-between;
    align-items: center;
  }

  .btn-cancel {
    background: white;
    border: 2px solid #555;
    color: #333;
    padding: 10px 20px;
    border-radius: 4px;
    font-size: 14px;
    font-weight: bold;
    cursor: pointer;
  }

  .btn-update {
    background: #8B0000;
    color: white;
    border: none;
    padding: 10px 28px;
    border-radius: 4px;
    font-size: 14px;
    font-weight: bold;
    cursor: pointer;
  }
</style>
</head>
<body>

<div class="container">

  <!-- Legal Form Row -->
  <div class="form-row">
    <div class="field-group">
      <label class="field-label">Legal Form of Entity (if the Owner is not a natural person)</label>
      <select>
        <option>-- Select --</option>
        <option>Corporation</option>
        <option>LLC</option>
      </select>
    </div>
    <div class="field-group">
      <label class="field-label">&nbsp;</label>
      <input type="text" placeholder="Other Legal Form of Entity">
    </div>
  </div>

  <!-- Owner Taxpayer ID -->
  <div class="taxpayer-block">
    <div class="taxpayer-header">
      <label class="field-label">Owner Taxpayer ID</label>
      <button class="btn-clear" onclick="clearTaxpayerID()">
        Clear
        <span class="tooltip">Clears Taxpayer ID selection &amp; values</span>
      </button>
    </div>

    <div class="radio-group">
      <label class="radio-option"><input type="radio" name="taxId" value="ein"> EIN</label>
      <label class="radio-option"><input type="radio" name="taxId" value="ssn" checked> SSN/ITIN</label>
      <label class="radio-option"><input type="radio" name="taxId" value="foreign"> Foreign ID</label>
    </div>

    <div class="fields-row">
      <input type="text" id="foreignId" placeholder="Foreign ID">
      <input type="text" id="ownership" placeholder="% of Ownership">
    </div>
  </div>

  <!-- Note -->
  <div class="note-box">
    <strong>Note:</strong> After adding or updating an owner, you must click the +
    <span class="keyword">Add</span> or <span class="keyword">Update</span> button to save your changes.
  </div>

  <!-- Footer -->
  <div class="footer-row">
    <button class="btn-cancel">✕ Cancel</button>
    <button class="btn-update">Update</button>
  </div>

</div>

<script>
  function clearTaxpayerID() {
    // Uncheck all radio buttons
    document.querySelectorAll('input[name="taxId"]').forEach(r => r.checked = false);
    // Clear text fields
    document.getElementById('foreignId').value = '';
    document.getElementById('ownership').value = '';
  }
</script>

</body>
</html>


    



<!DOCTYPE html>
<html>

<head>
    <title>Date Picker Table Example</title>
    <script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
        }

        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }

        button:disabled {
            background-color: #ccc;
            cursor: not-allowed;
        }
    </style>
</head>

<body>
    <h1>Date Picker Table Example</h1>
    <input type="date" id="dateInput" />
    <button id="addDateBtn" disabled>Add Date</button>

    <table id="dateTable">
        <tr>
            <th>Date</th>
            <th>Action</th>
        </tr>
    </table>

    <script>
        $(document).ready(function () {
            // Load existing dates from localStorage
            let dates = JSON.parse(localStorage.getItem('dates')) || [];

            // Function to render table
            function renderTable() {
                const table = $('#dateTable');
                table.find('tr:gt(0)').remove(); // remove all rows except header
                dates.forEach(date => {
                    table.append(`<tr>
                        <td>${date}</td>
                        <td><button class="deleteBtn" data-date="${date}">Delete</button></td>
                    </tr>`);
                });
            }

            renderTable();

            // Enable add button when date is selected
            $('#dateInput').on('change', function () {
                $('#addDateBtn').prop('disabled', !this.value);
            });

            // Add date
            $('#addDateBtn').click(function () {
                const selectedDate = $('#dateInput').val();

                if (!selectedDate) return;

                if (dates.includes(selectedDate)) {
                    alert('Date already exists!');
                } else {
                    dates.push(selectedDate);
                    localStorage.setItem('dates', JSON.stringify(dates));
                    renderTable();
                }

                $('#dateInput').val(''); // Clear input
                $('#addDateBtn').prop('disabled', true); // Disable button
            });

            // Delete date
            $(document).on('click', '.deleteBtn', function () {
                const dateToDelete = $(this).data('date');
                dates = dates.filter(d => d !== dateToDelete);
                localStorage.setItem('dates', JSON.stringify(dates));
                renderTable();
            });
        });
    </script>
</body>

</html>
