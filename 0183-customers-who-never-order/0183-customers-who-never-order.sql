# Write your MySQL query statement below
SELECT name as Customers
from Customers AS c
left join Orders as o
on c.id = o.customerid
where customerId is null;