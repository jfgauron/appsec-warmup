#!/usr/bin/env python
# -*- coding: utf-8 -*-

from CTFd.utils import set_config
from CTFd.utils.crypto import verify_password
from tests.helpers import *


def test_api_users_get_public():
    """Can a user get /api/v1/users if users are public"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            set_config('account_visibility', 'public')
            r = client.get('/api/v1/users')
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users')
            assert r.status_code == 302
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users')
            assert r.status_code == 404
    destroy_ctfd(app)


def test_api_users_get_private():
    """Can a user get /api/v1/users if users are public"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            set_config('account_visibility', 'public')
            r = client.get('/api/v1/users')
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users')
            assert r.status_code == 302
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users')
            assert r.status_code == 404
    destroy_ctfd(app)


def test_api_users_get_admins():
    """Can a user get /api/v1/users if users are public"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            set_config('account_visibility', 'public')
            r = client.get('/api/v1/users')
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users')
            assert r.status_code == 302
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users')
            assert r.status_code == 404
    destroy_ctfd(app)


def test_api_users_post_non_admin():
    """Can a user post /api/v1/users if not admin"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.post('/api/v1/users', json="")
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_users_post_admin():
    """Can a user post /api/v1/users if admin"""
    app = create_ctfd()
    with app.app_context():
        with login_as_user(app, 'admin') as client:
            # Create user
            r = client.post('/api/v1/users', json={
                "name": "user",
                "email": "user@user.com",
                "password": "password"
            })
            assert r.status_code == 200

            # Make sure password was hashed properly
            user = Users.query.filter_by(email='user@user.com').first()
            assert user
            assert verify_password('password', user.password)

            # Make sure user can login with the creds
            client = login_as_user(app)
            r = client.get('/profile')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_users_post_admin_with_attributes():
    """Can a user post /api/v1/users with user settings"""
    app = create_ctfd()
    with app.app_context():
        with login_as_user(app, 'admin') as client:
            # Create user
            r = client.post('/api/v1/users', json={
                "name": "user",
                "email": "user@user.com",
                "password": "password",
                "banned": True,
                "hidden": True,
                "verified": True
            })
            assert r.status_code == 200

            # Make sure password was hashed properly
            user = Users.query.filter_by(email='user@user.com').first()
            assert user
            assert verify_password('password', user.password)
            assert user.banned
            assert user.hidden
            assert user.verified
    destroy_ctfd(app)


def test_api_team_get_public():
    """Can a user get /api/v1/team/<user_id> if users are public"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            set_config('account_visibility', 'public')
            gen_user(app.db)
            r = client.get('/api/v1/users/2')
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 302
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 404
    destroy_ctfd(app)


def test_api_team_get_private():
    """Can a user get /api/v1/users/<user_id> if users are private"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            set_config('account_visibility', 'public')
            r = client.get('/api/v1/users/2')
            print(r.__dict__)
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 200
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 404
    destroy_ctfd(app)


def test_api_team_get_admin():
    """Can a user get /api/v1/users/<user_id> if users are viewed by admins only"""
    app = create_ctfd()
    with app.app_context():
        with login_as_user(app, 'admin') as client:
            gen_user(app.db)
            set_config('account_visibility', 'public')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 200
            set_config('account_visibility', 'private')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 200
            set_config('account_visibility', 'admins')
            r = client.get('/api/v1/users/2')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_patch_non_admin():
    """Can a user patch /api/v1/users/<user_id> if not admin"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with app.test_client() as client:
            r = client.patch('/api/v1/users/2', json="")
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_patch_admin():
    """Can a user patch /api/v1/users/<user_id> if admin"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app, 'admin') as client:
            r = client.patch('/api/v1/users/2', json={
                "name": "user",
                "email": "user@ctfd.io",
                "password": "password",
                "country": "US",
                "verified": True
            })
            assert r.status_code == 200
            user_data = r.get_json()['data'][0]
            assert user_data['country'] == 'US'
            assert user_data['verified'] is True
    destroy_ctfd(app)


def test_api_user_delete_non_admin():
    """Can a user delete /api/v1/users/<user_id> if not admin"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with app.test_client() as client:
            r = client.delete('/api/v1/teams/2', json="")
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_delete_admin():
    """Can a user patch /api/v1/users/<user_id> if admin"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app, 'admin') as client:
            r = client.delete('/api/v1/users/2', json="")
            assert r.status_code == 200
            assert r.get_json().get('data') is None
    destroy_ctfd(app)


def test_api_user_get_me_not_logged_in():
    """Can a user get /api/v1/users/me if not logged in"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.get('/api/v1/users/me')
            assert r.status_code == 302
    destroy_ctfd(app)


def test_api_user_get_me_logged_in():
    """Can a user get /api/v1/users/me if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/me')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_patch_me_not_logged_in():
    """Can a user patch /api/v1/users/me if not logged in"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.patch('/api/v1/users/me', json="")
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_patch_me_logged_in():
    """Can a user patch /api/v1/users/me if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.patch('/api/v1/users/me', json={"name": "user",
                                                       "email": "user@ctfd.io",
                                                       "password": "password",
                                                       "confirm": "password",
                                                       "country": "US"})
            assert r.status_code == 200
            assert r.get_json()['data']['country'] == 'US'
    destroy_ctfd(app)


def test_api_user_get_me_solves_not_logged_in():
    """Can a user get /api/v1/users/me/solves if not logged in"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.get('/api/v1/users/me/solves')
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_get_me_solves_logged_in():
    """Can a user get /api/v1/users/me/solves if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/me/solves')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_get_solves():
    """Can a user get /api/v1/users/<user_id>/solves if logged in"""
    app = create_ctfd(user_mode="users")
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/2/solves')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_get_me_fails_not_logged_in():
    """Can a user get /api/v1/users/me/fails if not logged in"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.get('/api/v1/users/me/fails')
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_get_me_fails_logged_in():
    """Can a user get /api/v1/users/me/fails if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/me/fails')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_get_fails():
    """Can a user get /api/v1/users/<user_id>/fails if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/2/fails')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_get_me_awards_not_logged_in():
    """Can a user get /api/v1/users/me/awards if not logged in"""
    app = create_ctfd()
    with app.app_context():
        with app.test_client() as client:
            r = client.get('/api/v1/users/me/awards')
            assert r.status_code == 403
    destroy_ctfd(app)


def test_api_user_get_me_awards_logged_in():
    """Can a user get /api/v1/users/me/awards if logged in"""
    app = create_ctfd(user_mode="users")
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/me/awards')
            assert r.status_code == 200
    destroy_ctfd(app)


def test_api_user_get_awards():
    """Can a user get /api/v1/users/<user_id>/awards if logged in"""
    app = create_ctfd()
    with app.app_context():
        register_user(app)
        with login_as_user(app) as client:
            r = client.get('/api/v1/users/2/awards')
            assert r.status_code == 200
    destroy_ctfd(app)
