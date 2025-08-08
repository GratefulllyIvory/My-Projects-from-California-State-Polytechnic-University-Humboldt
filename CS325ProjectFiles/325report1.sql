spool report1-results.txt
PROMPT -- Daniel Desforges CS325 Fall 2020 12/11/2020
set pagesize 50;
PROMPT                   Report1 CustomerPurchase List
select InstrumentID, Purchases, Name as "PurchasedBy", PhoneNumber
from CustomerList, Instrumentz
where CustomerID = PurchaseID
ORDER BY Name;
spool off

