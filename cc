// Define once (inside the page/model class)
private static void AppendCitationTable<T>(
    StringBuilder sb,
    IEnumerable<T> items,
    long crcClaimId,
    int commentTypeId,
    Func<T,long?> getCRCommentID,
    Func<T,long?> getDocID,
    Func<T,string> getPageFrom,
    Func<T,string> getPageTo,
    Func<T,string> getComments)
{
    foreach (var item in items)
    {
        sb.Append("<Table1>");
        sb.Append(GenerateTag("CRCClaimID",  crcClaimId));
        sb.Append(GenerateTag("CRCommentID", getCRCommentID(item)));
        sb.Append(GenerateTag("CRCommentTypeID", commentTypeId));
        sb.Append(GenerateTag("DocID",       getDocID(item)));
        sb.Append(GenerateTag("PageFrom",    getPageFrom(item)));
        sb.Append(GenerateTag("PageTo",      getPageTo(item)));
        sb.Append(GenerateTag("Comments",    getComments(item)));
        sb.Append("</Table1>");
    }
}
var sources = new[]
{
    (Items: AssertedDamageTypeList,  TypeId: 83),
    (Items: PerimeterTypeList,       TypeId: 84),
    (Items: PropertyDamageLevelList, TypeId: 85),
};

foreach (var src in sources)
{
    if (src.Items != null && src.Items.Count > 0)
        AppendCitationTable(docCitationXML, src.Items, CRCClaimID, src.TypeId);
}

if (AssertedDamageTypeList?.Count > 0)
    AppendCitationTable(docCitationXML, AssertedDamageTypeList, CRCClaimID, 83,
        x => x.CRCommentID, x => x.DocID, x => x.PageFrom, x => x.PageTo, x => x.Comments);

if (PerimeterTypeList?.Count > 0)
    AppendCitationTable(docCitationXML, PerimeterTypeList, CRCClaimID, 84,
        x => x.CRCommentID, x => x.DocID, x => x.PageFrom, x => x.PageTo, x => x.Comments);

if (PropertyDamageLevelList?.Count > 0)
    AppendCitationTable(docCitationXML, PropertyDamageLevelList, CRCClaimID, 85,
        x => x.CRCommentID, x => x.DocID, x => x.PageFrom, x => x.PageTo, x => x.Comments);
