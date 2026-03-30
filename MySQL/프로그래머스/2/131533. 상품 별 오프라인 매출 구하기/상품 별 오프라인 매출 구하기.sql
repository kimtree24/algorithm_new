select p.product_code, sum(s.sales_amount * p.price) as sales
from offline_sale as s
join product as p on s.product_id = p.product_id
group by p.product_code
order by sales desc, p.product_code asc;