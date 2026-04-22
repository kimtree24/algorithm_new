select year(o.sales_date) as year, 
        month(o.sales_date) as month, 
        i.gender,
        count(distinct i.user_id) as users
from user_info as i
join online_sale as o on i.user_id = o.user_id
group by year(o.sales_date), month(o.sales_date), i.gender
having i.gender is not null
order by year, month, i.gender