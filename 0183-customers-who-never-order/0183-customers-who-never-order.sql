# Write your MySQL query statement below
select name as Customers
from Customers
where id NOT IN(
    Select CustomerId
    From Orders
);
