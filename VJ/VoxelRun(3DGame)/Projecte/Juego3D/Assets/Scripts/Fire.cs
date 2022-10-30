using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fire : MonoBehaviour
{
    public AudioSource sound;
    public GameObject cannonBall, humoCanon;
    public Transform firePoint;
    public float fireForce = 500f;
    bool isFiring = false;
    public bool start = false;

    float cont = 3f;
    private void Update()
    {
        if (isFiring && start)
        {
            if (cont >= 2f)
            {
                cont = 0f;

                sound.Play();
                Quaternion rotation = Quaternion.Euler(0, 180, 0);
                Vector3 offset = new Vector3(0, 0, -3);
                Instantiate(humoCanon, firePoint.position+offset, rotation);
                Instantiate(cannonBall, firePoint.position, Quaternion.identity);
            }
            else cont += Time.deltaTime;
        }
    }
    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            if (other.gameObject.GetComponent<Movement>().active) isFiring = true;

        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            if (other.gameObject.GetComponent<Movement>().active) isFiring = false;

        }
    }
}
