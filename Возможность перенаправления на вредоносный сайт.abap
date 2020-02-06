DATA: str_dest TYPE c.
str_dest = request->get_form_field( 'dest' ).
response->redirect( str_dest ).

"http://trusted.example.com/ecommerce/redirect.asp?dest=http://evilsite.com/"

http://trusted.example.com/ecommerce/redirect.asp?dest=%77%69%6C%79%68%61%63%6B%65%72%2E%63%6F%6D