@page
@model PrivacyModel
@{
    ViewData["Title"] = "Real Property Claim Evaluation";
}
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" />

<div class="container-fluid mt-3">
    <h4>Real Property Claim Evaluation</h4>
    <div class="row">
        <!-- Left Column -->
        <div class="col-md-6">
            <!-- Claim Information -->
            <div class="card shadow-sm mb-4">
                <div class="card-header d-flex justify-content-between align-items-center">
                    <strong>Claim Information</strong>
                    <button class="btn btn-sm btn-outline-secondary" data-bs-toggle="collapse" data-bs-target="#claimInfo">−</button>
                </div>
                <div id="claimInfo" class="collapse show card-body">
                    <p><strong>CQ ID:</strong> 10002126</p>
                    <p><strong>Claim ID:</strong> 5906</p>
                    <p><strong>Loss Location:</strong> 123 Sweet St, Washington, DC 20523-0001</p>
                    <div class="table-responsive">
                        <table class="table table-sm table-bordered">
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
            </div>

            <!-- Documents -->
            <div class="card shadow-sm mb-4">
                <div class="card-header d-flex justify-content-between align-items-center">
                    <strong>Documents</strong>
                    <button class="btn btn-sm btn-outline-secondary" data-bs-toggle="collapse" data-bs-target="#documents">−</button>
                </div>
                <div id="documents" class="collapse show card-body">
                    <div class="table-responsive">
                        <table class="table table-sm table-bordered">
                            <thead>
                                <tr>
                                    <th>Document ID</th>
                                    <th>Document Type</th>
                                    <th>Upload Date</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr><td>18192</td><td>Final Notice Release_1010051</td><td>08/21/2024</td></tr>
                                <tr><td>18191</td><td>Final Notice Release_1010056</td><td>08/21/2024</td></tr>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>

        <!-- Right Column -->
        <div class="col-md-6">
            <!-- Location Damage Level -->
            <div class="card shadow-sm mb-4">
                <div class="card-header d-flex justify-content-between align-items-center">
                    <strong>Location Damage Level</strong>
                    <button class="btn btn-sm btn-outline-secondary" data-bs-toggle="collapse" data-bs-target="#damageLevel">−</button>
                </div>
                <div id="damageLevel" class="collapse show card-body">
                    <div class="mb-3">
                        <label>1. Fire Perimeter:</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="fire" /> Inside</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="fire" /> Outside</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="fire" /> Unknown</div>
                    </div>
                    <div class="mb-3">
                        <label>1a. Has Documented Proof?</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="proof" /> Yes</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="proof" /> No</div>
                    </div>
                    <div class="mb-3">
                        <label>2. Damage Type:</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="damage" /> Destroyed</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="damage" /> Smoke, Soot, and Ash</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="damage" /> Partial Damage</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="damage" /> Unknown</div>
                    </div>
                    <div class="mb-3">
                        <label>3. Damage Not Related - Caused by an Included Fire?</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="relatedFire" /> Yes</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="relatedFire" /> No</div>
                    </div>
                </div>
            </div>

            <!-- Property Identification -->
            <div class="card shadow-sm mb-4">
                <div class="card-header d-flex justify-content-between align-items-center">
                    <strong>Property Identification</strong>
                    <button class="btn btn-sm btn-outline-secondary" data-bs-toggle="collapse" data-bs-target="#property">−</button>
                </div>
                <div id="property" class="collapse show card-body">
                    <p><strong>1. Owner:</strong></p>
                    <p><strong>2. Loss Address:</strong> 123 Sweet St, Washington, DC 20523-0001</p>
                    <p><strong>3. APN:</strong> 054-160-008-000</p>
                    <p><strong>4. Fire:</strong></p>
                    <div class="mb-2">
                        <label>5. Is this a claim for ownership of the property?</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="ownership" /> Yes</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="ownership" /> No</div>
                    </div>
                    <div class="mb-2">
                        <label>5a. Does the Claimant own a structure on the property?</label><br />
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="structure" /> Yes</div>
                        <div class="form-check form-check-inline"><input class="form-check-input" type="radio" name="structure" /> No</div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>