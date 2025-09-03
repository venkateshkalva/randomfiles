// Common shape used only for output
public record CitationRow(long? CRCommentID, long? DocID, string PageFrom, string PageTo, string Comments);

// One writer for all lists
private static void AppendCitationTables(StringBuilder sb, IEnumerable<CitationRow> rows, long crcClaimId, int commentTypeId)
{
    foreach (var r in rows)
    {
        sb.Append("<Table1>");
        sb.Append(GenerateTag("CRCClaimID",  crcClaimId));
        sb.Append(GenerateTag("CRCommentID", r.CRCommentID));
        sb.Append(GenerateTag("CRCommentTypeID", commentTypeId));
        sb.Append(GenerateTag("DocID",       r.DocID));
        sb.Append(GenerateTag("PageFrom",    r.PageFrom));
        sb.Append(GenerateTag("PageTo",      r.PageTo));
        sb.Append(GenerateTag("Comments",    r.Comments));
        sb.Append("</Table1>");
    }
}

// Where you build XML
if (AssertedDamageTypeList?.Any() == true)
{
    var rows = AssertedDamageTypeList.Select(x =>
        new CitationRow(x.CRCommentID, x.DocID, x.PageFrom, x.PageTo, x.Comments));
    AppendCitationTables(docCitationXML, rows, CRCClaimID, 83);
}

if (PerimeterTypeList?.Any() == true)
{
    var rows = PerimeterTypeList.Select(x =>
        new CitationRow(x.CRCommentID, x.DocID, x.PageFrom, x.PageTo, x.Comments));
    AppendCitationTables(docCitationXML, rows, CRCClaimID, 84);
}

if (PropertyDamageLevelList?.Any() == true)
{
    var rows = PropertyDamageLevelList.Select(x =>
        new CitationRow(x.CRCommentID, x.DocID, x.PageFrom, x.PageTo, x.Comments));
    AppendCitationTables(docCitationXML, rows, CRCClaimID, 85);
}
