select Max(salary) as SecondHighestSalary from Employee where salary Not in(
select Max(salary) from Employee);
