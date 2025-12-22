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
