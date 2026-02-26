select i.name as name , i.datetime as datetime
from animal_ins as i
left join animal_outs as o on i.animal_id = o.animal_id
where o.name is null and i.name is not null
order by datetime
limit 3