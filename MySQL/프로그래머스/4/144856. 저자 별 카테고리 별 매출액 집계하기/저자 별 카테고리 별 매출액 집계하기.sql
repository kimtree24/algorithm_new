select b.author_id, a.author_name, b.category, sum(bs.sales * b.price) as total_sales
from book as b
join author as a on b.author_id = a.author_id
join book_sales as bs on b.book_id = bs.book_id
where bs.sales_date >= '2022-01-01' and bs.sales_date < '2022-02-01'
group by a.author_name, b.category
order by b.author_id, b.category desc;

