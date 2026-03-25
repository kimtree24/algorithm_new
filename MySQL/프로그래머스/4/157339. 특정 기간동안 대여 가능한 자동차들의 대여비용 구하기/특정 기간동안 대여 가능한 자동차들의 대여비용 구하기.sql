select crcc.car_id, crcc.car_type, floor(crcc.daily_fee * 30 * (100 - crcdp.discount_rate) / 100) as fee
from car_rental_company_car as crcc
join car_rental_company_discount_plan as crcdp
    on crcc.car_type = crcdp.car_type
    and crcdp.duration_type = '30일 이상'
where crcc.car_type in ('세단', 'SUV')

and not exists(
    select 1
    from car_rental_company_rental_history as crcrh
    where crcrh.car_id = crcc.car_id
        and crcrh.start_date <= '2022-11-30'
        and crcrh.end_date >= '2022-11-01'
)

and floor(crcc.daily_fee * 30 * (100 - crcdp.discount_rate) / 100) >= 500000
and floor(crcc.daily_fee * 30 * (100 - crcdp.discount_rate) / 100) < 2000000

order by fee desc, crcc.car_type asc, crcc.car_id desc;