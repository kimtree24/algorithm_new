select f.flavor
from first_half as f
join july as j on f.flavor = j.flavor
group by f.flavor
order by sum(f.total_order + j.total_order) desc
limit 3;