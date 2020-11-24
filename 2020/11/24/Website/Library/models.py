from django.db import models

# Create your models here.
class Book(models.Model):
    Title = models.CharField(max_length = 500)
    Author = models.CharField(max_length = 500)
    Price = models.FloatField(max_length = 10)
    Publish_Time = models.DateTimeField("Publish_Time")

class Worker(models.Model):
    Name = models.CharField(max_length = 500)
