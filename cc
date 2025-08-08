public IActionResult OnPostEdit(MyFormData formData)
{
    var list = HttpContext.Session.GetObject<List<MyFormData>>(SessionKey) ?? new List<MyFormData>();

    var existing = list.FirstOrDefault(x => x.Id == formData.Id);
    if (existing != null)
    {
        // Update only what’s needed; or use AutoMapper/etc.
        existing.Name = formData.Name;
        existing.SomeField = formData.SomeField;
        // ...other fields
    }

    HttpContext.Session.SetObject(SessionKey, list);
    return RedirectToPage();
}

public IActionResult OnPostDelete(int id)
{
    var list = HttpContext.Session.GetObject<List<MyFormData>>(SessionKey) ?? new List<MyFormData>();

    var itemToRemove = list.FirstOrDefault(x => x.Id == id);
    if (itemToRemove != null)
        list.Remove(itemToRemove);

    HttpContext.Session.SetObject(SessionKey, list);
    return RedirectToPage();
}
