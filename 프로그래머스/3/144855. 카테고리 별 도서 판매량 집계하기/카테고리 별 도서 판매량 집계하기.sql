select category, sum(bs.sales) as total_sales
from book as b
join book_sales as bs on b.book_id = bs.book_id
where year(bs.sales_date) = 2022 and month(bs.sales_date) = 1
group by category
order by category