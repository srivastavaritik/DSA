# Write your MySQL query statement below
select distinct name from salesPerson where sales_id not in
(select sales_id from orders where
com_id = (select com_id from company where name="red"));