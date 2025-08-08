spool 325lab12-out.txt
PROMPT -- Daniel Desforges and Daniel Villanueva 11/13/2020

PROMPT lab problem 1
DROP VIEW empl_salaries;
CREATE VIEW empl_salaries AS
SELECT empl_last_name, salary
FROM empl; 

PROMPT lab problem 2
Select*
from empl_salaries;

PROMPT lab problem 3
SELECT MAX(salary)
from empl_salaries;

PROMPT lab problem 4
drop view earliest_hires;
CREATE VIEW earliest_hires(job_title, earliest_hiredate) AS
select job_title, min(hiredate)
from empl;
group by job_title;

PROMPT lab problem 5
select * 
from earliest_hires;

PROMPT lab problem 6
select max(earliest_hiredate)
from earliest_hires;

spool off
