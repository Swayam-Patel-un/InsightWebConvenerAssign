from django.db import models

# Create your models here.

class Category(models.Model):
    catego = models.CharField(max_length=50)

    def __str__(self):
        return self.catego

class Article(models.Model):
    title = models.CharField(max_length=255)
    author = models.CharField(max_length=255)
    publishingDate = models.DateField(null=True)
    category= models.ForeignKey(Category,on_delete=models.CASCADE)
