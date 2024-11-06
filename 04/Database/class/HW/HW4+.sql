-- Active: 1715537699162@@127.0.0.1@5432@dvdrental@public
-- q2
CREATE OR REPLACE FUNCTION func(Id INT) RETURNS TABLE(name character varying(255),rent_count INT) AS $$
	BEGIN
		RETURN QUERY SELECT f.title, COUNT(*)::integer
		FROM film AS f
		JOIN film_actor AS fc ON fc.film_id = f.film_id
		JOIN inventory AS inv ON inv.film_id = f.film_id
		JOIN rental AS ren ON ren.inventory_id = inv.inventory_id
		WHERE fc.actor_id = Id
		GROUP BY f.title;
	END;
	$$ LANGUAGE plpgsql;

SELECT * FROM func (1);
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q3
CREATE TABLE my_table (
    customer_id int,
    profit numeric,
    pay_day_ date,
    avg_pay numeric
);

create or replace procedure customer_payments(p_first_name varchar, p_last_name varchar)
as $$
declare v_customer_id int;
v_payment_id int;
v_amount numeric;
v_payment_date date;
v_total_payments numeric;
v_avg_payment numeric;
begin
	select cu.customer_id into v_customer_id
	from customer as cu
	where cu.first_name = p_first_name and cu.last_name = p_last_name;

	select avg(pa.amount) into v_avg_payment
	from payment as pa
	where pa.customer_id = v_customer_id;

	for v_payment_id, v_amount, v_payment_date in
		select p.payment_id, p.amount, p.payment_date
		from payment as p
		where p.customer_id = v_customer_id
	loop	
		v_total_payments := round(v_amount * 0.10, 2);

		insert into my_table (avg_pay, pay_day_, profit, customer_id)
			values(v_avg_payment, date(v_payment_date), v_total_payments, v_customer_id);
	end loop;
	
end; $$
language plpgsql;

CALL customer_payments ('Mary', 'Smith');

SELECT * FROM my_table;
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q4
WITH
    film_analysis AS (
        SELECT
            c.name AS category,
            f.title AS name,
            f.length,
            f.length - lag(f.length) OVER (
                PARTITION BY
                    c.name
                ORDER BY f.length
            ) AS per_diff,
            f.length - lead(f.length) OVER (
                PARTITION BY
                    c.name
                ORDER BY f.length
            ) AS post_diff
        FROM
            film_category AS fc
            JOIN film f ON fc.film_id = f.film_id
            JOIN category AS c ON fc.category_id = c.category_id
    )
SELECT
    category,
    name,
    LENGTH,
    per_diff,
    post_diff
FROM film_analysis;
----------------------------------------------------------------------------
----------------------------------------------------------------------------
----------------------------------------------------------------------------
-- q5
SELECT
    EXTRACT(
        MONTH
        FROM rental_date
    ) AS month,
    film.rating,
    SUM(payment.amount) AS total_payment,
    LAG(SUM(payment.amount)) OVER (
        PARTITION BY
            film.rating
        ORDER BY EXTRACT(
                MONTH
                FROM rental_date
            )
    ) AS prev_month_sales,
    LEAD(SUM(payment.amount)) OVER (
        PARTITION BY
            film.rating
        ORDER BY EXTRACT(
                MONTH
                FROM rental_date
            )
    ) AS next_month_sales
FROM
    film
    JOIN inventory ON film.film_id = inventory.film_id
    JOIN rental ON inventory.inventory_id = rental.inventory_id
    JOIN payment ON rental.rental_id = payment.rental_id
GROUP BY
    EXTRACT(
        MONTH
        FROM rental_date
    ),
    film.rating
ORDER BY EXTRACT(
        MONTH
        FROM rental_date
    );