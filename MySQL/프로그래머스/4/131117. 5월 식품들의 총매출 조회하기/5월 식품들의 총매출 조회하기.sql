select o.product_id, p.product_name, sum(o.amount * p.price) as total_sales
from food_order as o
join food_product as p on o.product_id = p.product_id
where o.produce_date >= '2022-05-01' and o.produce_date < '2022-06-01'
group by o.product_id
order by total_sales desc, o.product_id;