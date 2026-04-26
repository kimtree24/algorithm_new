SELECT DISTINCT c.car_id
FROM car_rental_company_car c
JOIN car_rental_company_rental_history h
    ON c.car_id = h.car_id
WHERE c.car_type = '세단'
AND h.start_date >= '2022-10-01'
AND h.start_date <  '2022-11-01'
ORDER BY c.car_id desc