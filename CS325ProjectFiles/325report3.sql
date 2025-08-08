spool 325report3-results.txt
PROMPT-- Daniel Desforges CS 325 Fall 2020 12/11/2020
set pagesize 100
Prompt-- Compute syntax correct however not computing for set only computing individually
Prompt-- Report 3 Highest Transaction By Employees
BREAK ON RecievedPaymentID Skip 1
COMPUTE Max Label 'Highest Trasaction' OF PaymentAmount on RecievedPaymentID
Select RecievedPaymentID, PaymentAmount, OperatorName 
from ShopOperators
where OperatorName In ('Dante', 'Virgil')
Order By OperatorName;

spool off
