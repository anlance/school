USE red_packet;

# 红包表
CREATE TABLE red_packt (
id INT(12) NOT NULL AUTO_INCREMENT,
user_id INT(12) NOT NULL,
amount DECIMAL(16,2) NOT NULL,
send_time TIMESTAMP NOT NULL,
total INT(12) NOT NULL,
unit_amount DECIMAL(16,2) NOT NULL,
stock INT(12) NOT NULL,
VERSION INT(12) DEFAULT 0 NOT NULL,
note VARCHAR(256) NULL,
PRIMARY KEY clustered (id)
);

# 用户抢红包表
CREATE TABLE user_red_packet(
id INT(12) NOT NULL AUTO_INCREMENT,
red_packet_id INT(12) NOT NULL,
user_id INT(12) NOT NULL,
amount DECIMAL(16,2) NOT NULL,
grab_time TIMESTAMP NOT NULL,
note VARCHAR(256) NULL,
PRIMARY KEY clustered (id)
);




SELECT id,user_id,amount,send_time,total,unit_amount,stock,VERSION,note
        FROM red_packet
        WHERE id = 1;
        
        
SELECT
	a.id,
	a.amount,
	a.stock
FROM
	red_packet a
WHERE
	a.id = 1
UNION ALL
	SELECT
		MAX(b.user_id),
		SUM(b.amount),
		COUNT(*)
	FROM
		user_red_packet b
	WHERE
		b.red_packet_id = 1;


SELECT
		MAX(b.user_id),
		SUM(b.amount),
		COUNT(*)
	FROM
		user_red_packet b
	WHERE
		b.red_packet_id = 1;



INSERT INTO red_packet(user_id,amount,send_time,total,unit_amount,stock,note) VALUES(1,200000.00,NOW(),20000,10.00,20000,'20万金额，2万个红包，每个10元')

INSERT INTO red_packet(user_id,amount,send_time,total,unit_amount,stock,note) VALUES(1,2000*10,NOW(),20000,10.00,20000,'20万金额，2万个红包，每个10元')

TRUNCATE red_packet