PROMPT -- Daniel Desforges, Ward Nickle, and Jacob Castro: October 30 2020
start set-up-ex-tbls.sql

spool 325lab10-out.txt

PROMPT lab query 1
select job_title, mgr
from empl
where salary < 2000 
union
select job_title,mgr
from empl
where commission is NOT NULL;

PROMPT lab query 2
select job_title, mgr
from empl
where salary < 2000
intersect
select job_title, mgr
from empl
where commission is NOT NULL;

PROMPT lab query 3
select job_title, mgr
from empl
where salary < 2000
minus
select job_title, mgr
from empl
where commission is NOT NULL;

PROMPT lab query 4
select empl_last_name, 2*salary as TWICE_SALARY
from empl
where job_title = 'Clerk'
minus 
select empl_last_name, 2*salary as TWICE_SALARY
from empl
where hiredate < '01-JAN-2015'
order by TWICE_SALARY DESC;

PROMPT lab query 5
select empl_last_name, job_title, salary, commission
from empl
where commission is NOT NULL;
UPDATE empl
set commission = commission+100
where salary < 
	(select Avg(salary)
	from empl
	where job_title = 'Sales');
select empl_last_name, job_title, salary, commission
from empl;

PROMPT lab query 6 
DELETE from empl
where salary < 
	(select min(salary)
	from empl
	where job_title = 'Sales');
select empl_last_name, job_title, salary
from empl;
spool off
