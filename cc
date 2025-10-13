using System.IO;
using Microsoft.AspNetCore.StaticFiles;
using Microsoft.AspNetCore.Mvc;

public IActionResult DownloadOrOpen(string docPath, string fileName)
{
    // Example: you already have file bytes from cloud storage
    // byte[] fileBytes = CloudStorage.DownloadFromCloud(docPath).ContentBytes;
    byte[] fileBytes = GetFileBytesFromYourBlob(docPath); // replace with your method
    if (fileBytes == null || fileBytes.Length == 0)
        return NotFound();

    // sanitize filename (avoid directory traversal)
    fileName = Path.GetFileName(fileName ?? "file");

    // Determine content type using built-in provider
    var provider = new FileExtensionContentTypeProvider();
    string contentType;
    if (!provider.TryGetContentType(fileName, out contentType))
    {
        contentType = "application/octet-stream";
    }

    // Decide disposition: inline only for PDFs; attachment otherwise
    var ext = Path.GetExtension(fileName)?.ToLowerInvariant();
    var dispositionType = ext == ".pdf" ? "inline" : "attachment";

    // Build safe Content-Disposition header
    // Use RFC-compliant filename* for UTF-8 as well as a simple filename fallback
    var headerValue = $"{dispositionType}; filename=\"{fileName}\"; filename*=UTF-8''{Uri.EscapeDataString(fileName)}";

    // Remove any existing header (prevent duplicates) and add ours
    if (Response.Headers.ContainsKey("Content-Disposition"))
        Response.Headers.Remove("Content-Disposition");
    Response.Headers.Add("Content-Disposition", headerValue);

    return File(fileBytes, contentType);
}
