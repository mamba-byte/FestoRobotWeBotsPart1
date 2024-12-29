Bu proje, konsol tabanlı bir robot kontrol sistemi geliştirmeyi hedefler

Uygulama (App) ve Menüler:
	•	App sınıfı, kimlik doğrulama (Authentication) ve ana menü akışını yönetir.
	•	Menus (soyut) ve türetilmiş menüler (ConnectionMenu, MotionMenu, SensorMenu) kullanıcıyla etkileşim kurar.
	•	Robot ve Temel Kontrol:
	•	Robot sınıfı, FestoRobotAPI ile etkileşim kuran bir RobotControler nesnesi içerir. Robotun bağlantı, hareket, sensör gibi işlemlerine buradan erişilir.
	•	Sensörler, Harita ve Diğer Bileşenler:
	•	IRSensor, LidarSensor gibi sınıflar robotun çevre verilerini toplar.
	•	Map ve Mapper, sensör verilerini 2D ızgara üzerinde işleyip kaydedebilir.
	•	Point, Pose gibi yardımcı sınıflar konum ve yönelim hesaplamalarında kullanılır.
	•	Record basit dosya okuma/yazma işlemlerini üstlenir.
	•	Authentication ve RobotOperator sınıfları, kullanıcı erişim kodunu kontrol ederek doğru kimlik doğrulamasını sağlar.
	
