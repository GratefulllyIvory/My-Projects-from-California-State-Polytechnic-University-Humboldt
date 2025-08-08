
spool 325report2-results.txt
PROMPT -- Daniel Desforges CS325 FAll 2020 12/11/2020
set pagesize 100
column1 width 5
column2 width 12
column3 width 15
Prompt Complete List Of Antique Shop Instrument
PROMPT StringInstruments
BREAK ON StringInstrumentsID Duplicates
select Instrumentz.InstrumentID, concat(IsAntique, StringType) 
from Instrumentz, StringInstruments
where Instrumentz.InstrumentID = StringInstruments.InstrumentID;
PROMPT -- WindInstruments

select Instrumentz.InstrumentID, concat(IsAntique, WindType)
from Instrumentz, WindInstruments
where Instrumentz.InstrumentID = WindInstruments.InstrumentID;

PROMPT -- PrecussionInstruments

select Instrumentz.InstrumentID, concat(IsAntique, PrecussionType)
from Instrumentz, PrecussionInstruments
where Instrumentz.InstrumentID = PrecussionInstruments.InstrumentID;

spool off
