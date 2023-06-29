from django import forms
from .models import Article , Category


class ArticleForm(forms.ModelForm):

    class Meta:
        model = Article
        fields = ('title','author','publishingDate','category')
        labels = {
            'title':'Title',
            'author':'Author',
            'publishingDate':'Publishing Date',
            'category':'Category'
        }

    def __init__(self, *args, **kwargs):
        super(ArticleForm,self).__init__(*args, **kwargs)
        self.fields['category'].empty_label = "Select"