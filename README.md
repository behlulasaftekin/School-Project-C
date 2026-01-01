# School-Project-C
# 📱 GSM Abone Otomasyon Sistemi

> **Trakya Üniversitesi Bilgisayar Mühendisliği** 2. Sınıf kapsamında geliştirdiğim C projesi.

Bu proje, C programlama dili kullanılarak geliştirilmiş kapsamlı bir **GSM Abone Yönetim Sistemidir**. Proje sayesinde yeni abone kaydı, abone silme, bilgi güncelleme ve arama işlemleri hızlı ve düzenli bir şekilde yapılabilmektedir. **Visual Studio 2022** ortamında geliştirilmiştir.

---

## 🚀 Özellikler

* **Abone Yönetimi:** Yeni abone ekleme, mevcut aboneyi silme ve güncelleme işlemleri.
* **Arama ve Sorgulama:** İsim veya numara bazlı hızlı abone sorgulama.
* **Modüler Yapı:** Kodun okunabilirliğini ve yönetilebilirliğini artırmak için `veri_seti.h` (header) dosyası kullanılarak modüler bir yapı kuruldu.
* **Veri Kalıcılığı:** Abone verileri dosya sistemi üzerinde tutularak program kapansa bile verilerin korunması sağlandı (File I/O).

---

## 📂 Dosya Yapısı

Proje dosyaları ve görevleri aşağıdadır:

* `main.c`: Programın ana çalışma dosyasıdır. Menü yönetimi, kullanıcı etkileşimi ve ana fonksiyonlar burada yer alır.
* `veri_seti.h`: **(Önemli)** Projenin yapı taşıdır. Abone `struct` yapıları, fonksiyon prototipleri ve global veri tanımlamaları bu başlık dosyasında bulunur.

---

## 💻 Kurulum ve Çalıştırma

Bu proje **Visual Studio 2022** ile geliştirilmiştir, ancak herhangi bir C derleyicisi (GCC vb.) ile de çalıştırılabilir.

### Seçenek 1: Visual Studio 2022 ile Açma
1.  Repoyu klonlayın veya ZIP olarak indirin:
    ```bash
    git clone [https://github.com/behlulasaftekin/GSM-Abone-Otomasyonu.git](https://github.com/behlulasaftekin/GSM-Abone-Otomasyonu.git)
    ```
2.  Klasör içindeki `.sln` (Solution) dosyasına çift tıklayarak projeyi açın.
3.  Yukarıdaki **"Local Windows Debugger"** (veya F5) tuşuna basarak çalıştırın.

### Seçenek 2: GCC (Terminal) ile Derleme
Eğer terminal üzerinden çalıştırmak isterseniz proje dizinine gidip şu komutları uygulayın:

```bash
gcc main.c -o gsm_otomasyon
./gsm_otomasyon
```
### 🛠️Kullanılan Teknolojiler
Dil: C Programming Language

IDE: Visual Studio 2022

Veri Yapıları: Structs, Pointers

Yöntem: Modüler Programlama, Dosya İşlemleri (File I/O)

### 👤 İletişim
Behlül Asaf Tekin

🔗 GitHub Profilim: https://github.com/behlulasaftekin

💼 LinkedIn Profilim: https://www.linkedin.com/in/behl%C3%BCl-asaf-tekin-b3045531b/
