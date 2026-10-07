# Write your MySQL query statement belows
select round(score,2) as score, dense_rank() over (order by score desc) as 'rank'
from Scores