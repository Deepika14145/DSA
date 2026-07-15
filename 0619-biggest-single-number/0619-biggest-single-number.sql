# Write your MySQL query statement below
select MAX(num) as num
from (
    select num
    from MyNumbers
    group by num
    having count(*) = 1
) as temp;