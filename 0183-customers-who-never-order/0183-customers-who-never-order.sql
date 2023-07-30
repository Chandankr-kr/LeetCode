# Write your MySQL query statement below
select c1.name as Customers
from Customers c1
where id not in(select Orders.customerId from Orders );