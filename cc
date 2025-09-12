using Microsoft.AspNetCore.Mvc.ModelBinding;

public static class CustomValidators
{
    // prefix: pass "OtherPropertyForm" if your input names are prefixed; otherwise leave null.
    public static bool ValidateOtherPropertyForm(OtherPropertyForm m, ModelStateDictionary modelState, string prefix = null)
    {
        string K(string name) => string.IsNullOrEmpty(prefix) ? name : $"{prefix}.{name}";
        void Require(bool ok, string field, string message)
        {
            if (!ok) modelState.AddModelError(K(field), message);
        }
        bool IsEmpty(string? s) => string.IsNullOrWhiteSpace(s);
        bool HasVal<T>(T? v) where T : struct => v.HasValue;

        // ---- Base requireds (mirror your attributes) ----
        Require(!IsEmpty(m.OtherPersonalPropertyName), nameof(m.OtherPersonalPropertyName),
            "Personal property name is required.");

        Require(HasVal(m.IsProofOfOwnership), nameof(m.IsProofOfOwnership),
            "Proof of ownership is required.");

        Require(HasVal(m.IsProofOfDamageProvidedByFire), nameof(m.IsProofOfDamageProvidedByFire),
            "Proof of damage is required.");

        Require(HasVal(m.IsProofOfActualCash), nameof(m.IsProofOfActualCash),
            "Selection for actual cash value/cost of repair is required.");

        Require(HasVal(m.IsInsuranceInfoProvided), nameof(m.IsInsuranceInfoProvided),
            "Did the claimant provide insurance information? is required.");

        // ---- Conditional rules (adapted from your screenshots) ----
        // Ownership% required when ProofOfOwnership == 2
        if (m.IsProofOfOwnership == 2)
        {
            Require(HasVal(m.OtherOwnershipPercentage), nameof(m.OtherOwnershipPercentage),
                "Ownership % is required.");
        }

        // VIN/HIN required when type == 1 (Automobile/Watercraft/Other Vehicle)
        if (m.OtherPersonalPropertyID == 1)
        {
            Require(!IsEmpty(m.VINorHIN_Number), nameof(m.VINorHIN_Number),
                "VIN or HIN number is required.");
        }

        // Cost of repair required when IsProofOfActualCash == 2
        if (m.IsProofOfActualCash == 2)
        {
            Require(HasVal(m.CostofRepair), nameof(m.CostofRepair),
                "Cost of repair is required.");
        }

        // Coverage + Payment required when insurance info provided (2 or 3)
        if (m.IsInsuranceInfoProvided == 2 || m.IsInsuranceInfoProvided == 3)
        {
            Require(HasVal(m.CoverageLimit), nameof(m.CoverageLimit),
                "Coverage limit is required.");
            Require(HasVal(m.PaymentAmount), nameof(m.PaymentAmount),
                "Payment amount is required.");
        }

        // Optional: document metadata if you enforce uploads
        if (m.UploadedFile) // or whatever flag means a file is attached
        {
            Require(HasVal(m.DocumentTypeID), nameof(m.DocumentTypeID),
                "Document type is required.");
            Require(HasVal(m.MELienholderID), nameof(m.MELienholderID),
                "Lienholder is required.");
        }

        return modelState.IsValid;
    }
}

public IActionResult OnPostSessionSavePersonalPropertyReviewDetails()
{
    // If your inputs are not prefixed, omit the 3rd arg.
    if (!CustomValidators.ValidateOtherPropertyForm(OtherPropertyForm, ModelState /*, "OtherPropertyForm"*/))
    {
        showHideOtherPP = true;
        return Page();
    }

    // ... your save logic
}
