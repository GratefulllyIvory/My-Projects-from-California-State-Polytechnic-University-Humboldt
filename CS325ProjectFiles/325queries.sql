
spool 325query-results.txt
PROMPT -- Daniel Desforges CS325 Fall 2020 12/11/2020
PROMPT-- Query 1 Avg Item Sales
select avg(PaymentAmount) as "AverageItemCost"
from ShopOperators;

PROMPT -- Query 2 EmployeeComissionTotal
select SUM(PaymentAmount)*.05 as "Employee: 5% Commissions"
from ShopOperators
where OperatorName= 'Dante' OR
			OperatorName = 'Virgil'
Order By(select OperatorName
	from ShopOperators);

PROMPT -- Query 3 String Violin Instrument Locations With String Value
select  StringType, StoredLocation, IsString
from StringInstruments, Violins
where StringInstruments.InstrumentID = Violins.InstrumentID;

PROMPT -- Query 4 String Guitar Instrument Locations with InstrumentID
select  StringType, StoredLocation, StringInstruments.InstrumentID
from StringInstruments, Guitars
where StringInstruments.InstrumentID = Guitars.InstrumentID;

PROMPT -- Query 5 Wind Bugals Instrument Locations with Wind Value
select StoredLocation, IsWind, WindInstruments.InstrumentID
from WindInstruments, Bugals 
where WindInstruments.InstrumentID = Bugals.InstrumentID;

PROMPT -- Query 6 Wind Tubas Instrument Locations with WindType
select StoredLocation, WindInstruments.WindType, WindInstruments.InstrumentID
from WindInstruments, Tubas
where WindInstruments.InstrumentID = Tubas.InstrumentID;

PROMPT -- Query 7 Quantity at StoredLocation
Select COUNT(InstrumentID), StoredLocation 
from PrecussionInstruments
group by StoredLocation;

PROMPT -- Query 8 Pricing Of Antiques vs Non Antiques
select InstrumentID, IsAntique, PaymentAmount
from Instrumentz
INNER JOIN ShopOperators
ON Instrumentz.InstrumentID = ShopOperators.RecievedPaymentID;
spool off
