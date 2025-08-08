spool 325lab13a-out.txt;
PROMPT -- Daniel Desforges and Blake Callison

prompt lab query 1;
Select dept_name, salary
from dept, empl
where dept.dept_num = empl.dept_num
order by dept_name; 

prompt lab query 2;
set pagesize 50;
set feedback off;

Select dept_name, salary
from dept, empl
where dept.dept_num = empl.dept_num
order by dept_name;

prompt lab query 3;
drop sequence play_seq;
create sequence play_seq
start with 13 
increment by 100;

select play_seq.nextval from dual;
select play_seq.nextval from dual; 
select play_seq.currval from dual; 


prompt lab query 4;
set pagesize 14;
set feedback 6;

spool off 
