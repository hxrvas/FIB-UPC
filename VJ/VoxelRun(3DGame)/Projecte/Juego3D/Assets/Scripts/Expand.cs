using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Expand : MonoBehaviour
{

    Vector3 newScale;
    float speed = 20f;
    private void OnTriggerEnter(Collider other)
    {
        newScale = new Vector3(1.5f, 1.5f, 1.5f);
        transform.localScale = Vector3.Lerp(transform.localScale, newScale, speed * Time.deltaTime);
       
    }

    private void OnTriggerExit(Collider other)
    {
        newScale = new Vector3(0.5f, 0.5f, 0.5f);
        transform.localScale = Vector3.Lerp(transform.localScale, newScale, speed * Time.deltaTime);
    }
}
