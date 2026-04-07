select
    year(os.sales_date) as year,
    month(os.sales_date) as month,
    count(distinct os.user_id) as purchased_users,
    round( count(distinct os.user_id) /
          (select count(*)
          from user_info
          where year(joined) = 2021)
          ,1) as puchased_ratio
from user_info as ui
join online_sale as os on ui.user_id = os.user_id
where year(ui.joined) = 2021
group by year, month
order by year, month;