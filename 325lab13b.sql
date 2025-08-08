-- Blake Callison and Daniel Desforges

-- 11/20/2020

start set-up-ex-tbls.sql;

SPOOL 325lab13b.-out.txt

PROMPT Blake Callison and Daniel Deforges

PROMPT Lab Query 1

SELECT dept_name, salary
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY dept_name;


PROMPT Lab Query 2

ALTER TABLE dept
RENAME COLUMN dept_name TO Department;

SELECT Department, salary
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY Department;

PROMPT Lab Query 3

ALTER TABLE empl
RENAME COLUMN salary TO Dept_Salaries;

COLUMN Dept_Salaries FORMAT $9,000.00;

SELECT Department, Dept_Salaries
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY Department;

PROMPT Lab Query 4

BREAK ON Department;

SELECT Department, Dept_Salaries
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY Department;

PROMPT Lab Query 5

COMPUTE AVG OF Dept_Salaries ON Department;

SELECT Department, Dept_Salaries
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY Department;

PROMPT Lab Query 6

TTitle 'Departments';
SET PAGESIZE 14;
SET FEEDBACK off;

SELECT Department, Dept_Salaries
FROM dept, empl
WHERE dept.dept_num = empl.dept_num
ORDER BY Department;

PROMPT Lab Query 7

CLEAR BREAKS;
CLEAR COLUMNS;
CLEAR COMPUTES;

TTITLE off;

SET PAGESIZE 14;
SET FEEDBACK 6;

SPOOL off
