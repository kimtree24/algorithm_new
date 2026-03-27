select m.member_name,
        r.review_text,
        date_format(r.review_date, '%Y-%m-%d') as review_date
from member_profile as m
join rest_review as r
    on m.member_id = r.member_id
where m.member_id in (
    select member_id
    from rest_review
    group by member_id
    having count(*) = (
        select max(cnt)
        from(
            select count(*) as cnt
            from rest_review
            group by member_id
        ) as t
    )
)

order by review_date, review_text;
