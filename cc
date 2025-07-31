@page
@model IndexModel
@{
    ViewData["Title"] = "Real Property Claim Evaluation";
}

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">

<h2 class="mt-3">Real Property Claim Evaluation</h2>

<div class="d-flex flex-wrap justify-content-between gap-4">
    <!-- Claim Information -->
    <div class="flex-fill min-width-300" style="flex: 1 1 400px;">
        <h4>Claim Information</h4>
        <p><strong>CQ ID:</strong> 10002126</p>
        <p><strong>Claim ID:</strong> 5906</p>
        <p><strong>Loss Location:</strong> 123 Sweet St, Washington, DC 20523-0001</p>

        <div class="table-responsive">
            <table class="table table-bordered table-sm">
                <thead>
                    <tr>
                        <th>Claimant ID</th>
                        <th>Name</th>
                        <th>TaxPayer ID</th>
                        <th>Group ID</th>
                    </tr>
                </thead>
                <tbody>
                    <tr><td>1090764</td><td>ZackClaimant</td><td>****5692</td><td>300260</td></tr>
                    <tr><td>1090765</td><td>ZackClaimant</td><td>****5236</td><td>300260</td></tr>
                    <tr><td>1090766</td><td>ZackClaimant</td><td>****4564</td><td>300260</td></tr>
                    <tr><td>1090767</td><td>ZackClaimant</td><td>****5325</td><td>300260</td></tr>
                    <tr><td>1090768</td><td>ZackClaimant</td><td>****2597</td><td>300260</td></tr>
                </tbody>
            </table>
        </div>
    </div>

    <!-- Location Damage Level -->
    <div class="flex-fill min-width-300" style="flex: 1 1 400px;">
        <h4>Location Damage Level</h4>
        <form>
            <div class="form-group mb-3">
                <label>1. Fire Perimeter:</label><br />
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="firePerimeter" id="inside" />
                    <label class="form-check-label" for="inside">Inside</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="firePerimeter" id="outside" />
                    <label class="form-check-label" for="outside">Outside</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="firePerimeter" id="unknown" />
                    <label class="form-check-label" for="unknown">Unknown</label>
                </div>
            </div>

            <div class="form-group mb-3">
                <label>1a. Has Documented Proof?</label><br />
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="hasProof" id="proofYes" />
                    <label class="form-check-label" for="proofYes">Yes</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="hasProof" id="proofNo" />
                    <label class="form-check-label" for="proofNo">No</label>
                </div>
            </div>

            <div class="form-group mb-3">
                <label>2. Damage Type:</label><br />
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="damageType" id="smoke" />
                    <label class="form-check-label" for="smoke">Smoke, Soot, and Ash</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="damageType" id="partial" />
                    <label class="form-check-label" for="partial">Partial Damage</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="damageType" id="damageUnknown" />
                    <label class="form-check-label" for="damageUnknown">Unknown</label>
                </div>
            </div>

            <div class="form-group mb-3">
                <label>3. Damage Not Related - Caused by Included Fire?</label><br />
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="relatedFire" id="yes" />
                    <label class="form-check-label" for="yes">Yes</label>
                </div>
                <div class="form-check form-check-inline">
                    <input class="form-check-input" type="radio" name="relatedFire" id="no" />
                    <label class="form-check-label" for="no">No</label>
                </div>
            </div>
        </form>
    </div>
</div>

<!-- Documents Section -->
<div class="mt-4">
    <h4>Documents</h4>
    <div class="table-responsive">
        <table class="table table-bordered table-sm">
            <thead>
                <tr>
                    <th>Document ID</th>
                    <th>Document Type</th>
                    <th>Upload Date</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><a href="#">18192</a></td>
                    <td>Final Notice Of Release Deadline_1010051</td>
                    <td>08/21/2024</td>
                </tr>
                <tr>
                    <td><a href="#">18191</a></td>
                    <td>Final Notice Of Release Deadline_1010056</td>
                    <td>08/21/2024</td>
                </tr>
            </tbody>
        </table>
    </div>
</div>

<!-- Property Identification -->
<div class="mt-4">
    <h4>Property Identification</h4>
    <p><strong>Owner:</strong> </p>
    <p><strong>Loss Address:</strong> 123 Sweet St, Washington, DC 20523-0001</p>
    <p><strong>APN:</strong> 054-160-00</p>
    <p><strong>Fire:</strong></p>
</div>