-- Sean Fitzgerald and Daniel Desforges

set serveroutput on;

spool lab5-out.txt;

prompt Sean Fitzgerald and Daniel Desforges

create or replace function get_manager(empl_name varchar)
return varchar as
	mgr_name varchar;
BEGIN
	if exists select name from empl where name = empl_name then
		if (select count(name) from empl where name = empl_name) > 2 then
			return 'Name not unique';
		end if
	else
		return 'Not an employee';
	end if;

	select name
	from empl
	where mgr = (
		select mgr
		from empl
		where name = empl_name)
	into mgr_name;

	if exists select name from empl where name = mgr_name then
		return mgr_name;
	else
		return 'No manager';
	end if;
into mgr_name;
END;

create or replace function show_manager(empl_name varchar)
return varchar as
	mgr_name varchar;
BEGIN
	mgr_name := get_manager(empl_name);
	dbms_output.put_line(empl_name);
	return mgr_name;
END;

commit;

insert into empl
values (6, 'Ward', 'Astronaut', 7839, '17-Feb-20', 3, 0, 200);

define my_empl = select get_manager('Turner') from dual;
select '&my_empl' from dual;

select show_manager('Raimi') from dual;

select show_manager('King') from dual;

select show_manager('Wilbon') from dual;

select show_manager('Ward') from dual;

ROLLBACK;

spool off;
