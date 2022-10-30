using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameLogic : MonoBehaviour
{
    public Material skin0, skin1, skin2;
    List<Movement> players;
    private int cont;
    private float factMult;
    private bool finalForm = false;
    public bool changeOrDie = false;
    public bool hasWon = false;
    public Movement originalPlayer;
    public GameObject BigGuy;
    public GameObject playerPref;
    public GameObject finalMenuUI;
    public Text Score;
    public Text PlayerCont;
    public Text Money;
    int playerScore;
    public bool activaFinalMenu = false;
    public bool start = false;
    public GameObject START;
    bool WinDone = false;
    public bool scene5 = false;

    void Start()
    {
        factMult = 1f;
        players = new List<Movement>();
        cont = 1;
        playerScore = 0;
        players.Add(originalPlayer);
        Score.text = "Score: " + playerScore.ToString();
        PlayerCont.text = "        " + cont.ToString();

        GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Terrain");
        foreach (GameObject obj in allObjects)
        {
            if (obj.GetComponent<MoveTerrain>() != null) obj.GetComponent<MoveTerrain>().stop = true;
            if (obj.GetComponent<Fire>() != null) obj.GetComponent<Fire>().start = false;
        }

        GameObject[] allplayers = GameObject.FindGameObjectsWithTag("Player");
        int id = PlayerPrefs.GetInt("skinId");
        foreach (GameObject player in allplayers)
        {
            if (id == 0) player.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin0;
            else if (id == 1) player.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin1;
            else if (id == 2) player.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin2;
            if (player.GetComponent<Movement>() != null) player.GetComponent<Movement>().stop = true;
        }
        GameObject[] barreras = GameObject.FindGameObjectsWithTag("Dead");
        foreach (GameObject b in barreras)
        {
            if (b.GetComponent<functBarrera>() != null) b.GetComponent<functBarrera>().stop = true;
        } 
    }
   
    void Update()
    {
        if (!start)
        {
            if (Input.GetButtonDown("Jump"))
            {
                FindObjectOfType<AudioManager>().Play("Button");
                originalPlayer.Activate();
                START.SetActive(false);
                start = true;

                GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Terrain");
                foreach (GameObject obj in allObjects)
                {
                    if (obj.GetComponent<MoveTerrain>() != null) obj.GetComponent<MoveTerrain>().stop = false;
                    if (obj.GetComponent<Fire>() != null) obj.GetComponent<Fire>().start = true;
                }

                GameObject[] allplayers = GameObject.FindGameObjectsWithTag("Player");
                foreach (GameObject player in allplayers)
                {
                    if (player.GetComponent<Movement>() != null) player.GetComponent<Movement>().stop = false;
                }

                GameObject[] barreras = GameObject.FindGameObjectsWithTag("Dead");
                foreach (GameObject b in barreras)
                {
                    if (b.GetComponent<functBarrera>() != null) b.GetComponent<functBarrera>().stop = false;
                }
            }
        }
        else
        {
            if (!hasWon)
            {
                if (Input.GetKeyDown("m") && !finalForm)
                {
                    FindObjectOfType<AudioManager>().Play("Button");
                    spawnOne();
                }

                if (Input.GetKeyDown("n") && !finalForm)
                {
                    FindObjectOfType<AudioManager>().Play("Button");
                    killOne();
                }

                if (Input.GetButtonDown("Jump"))
                {
                    FindObjectOfType<AudioManager>().Play("Jump");
                    waveJump();
                }
                if (cont == 0) Invoke("restartCurrentScene", 0.5f);
                if (changeOrDie && !finalForm)
                {
                    if (cont >= 7)
                    {
                        
                        GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Player");
                        foreach (GameObject obj in allObjects)
                        {
                            players.Remove(obj.GetComponent<Movement>());
                            Destroy(obj);
                        }
                        FindObjectOfType<AudioManager>().Play("Grow");
                        Movement giant = Instantiate(BigGuy).GetComponent<Movement>();
                        giant.SetLogic(this);
                        giant.Activate();
                        int id = PlayerPrefs.GetInt("skinId");
                        if (id == 0) giant.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin0;
                        else if (id == 1) giant.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin1;
                        else if (id == 2) giant.transform.GetChild(0).transform.GetChild(1).GetComponent<SkinnedMeshRenderer>().material = skin2;
                        players.Add(giant);
                        cont -= 6;
                        giant.addScale(cont);
                        finalForm = true;
                        cont = 1;
                    }

                    else
                    {
                        GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Player");
                        foreach (GameObject obj in allObjects)
                        {
                            obj.GetComponent<Movement>().Die();
                            players.Remove(obj.GetComponent<Movement>());
                        }
                        cont = 0;
                    }
                }
            }

            else
            {
                if (!WinDone)
                {
                    WinDone = true;
                    float multi = 1f;
                    GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Terrain");
                    foreach (GameObject obj in allObjects)
                    {
                        if (obj.GetComponent<MoveTerrain>() != null) obj.GetComponent<MoveTerrain>().stop = true;
                    }

                    foreach (Movement player in players)
                    {
                        multi = player.getScale() / 6f;

                        if (multi <= 2f / 6f)
                        {

                            multi = 1f;
                        }

                        if (multi <= 4f / 6f)
                        {
                            multi = 2f;
                        }

                        if (multi <= 1f)
                        {
                            multi = 3f;
                        }


                        player.hasWon = true;
                    }
                    GameObject[] camera = GameObject.FindGameObjectsWithTag("MainCamera");
                    foreach (GameObject cam in camera)
                    {
                        cam.GetComponent<MoveTerrain>().stop = false;
                    }

                    print(multi);
                    print(playerScore);
                    playerScore *= (int)multi;
                    print(playerScore);
                    Money.text = "+" + playerScore.ToString();
                    int money = PlayerPrefs.GetInt("score");
                    money += playerScore;
                    PlayerPrefs.SetInt("score", money);
                    if (!scene5) Invoke("FinalMenuActive", 8f);
                    else Invoke("Credits", 8f);
                }
            }

            Score.text = "Score: " + playerScore.ToString();
            PlayerCont.text = "        " + cont.ToString();
        }

        if (Input.GetKey("1"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            NextLevel1();
        }

        if (Input.GetKey("2"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            NextLevel2();
        }

        if (Input.GetKey("3"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            NextLevel3();
        }

        if (Input.GetKey("4"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            NextLevel4();
        }

        if (Input.GetKey("5"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            NextLevel5();
        }


        if (Input.GetKeyDown("g"))
        {
            FindObjectOfType<AudioManager>().Play("Button");
            GameObject[] allplayers = GameObject.FindGameObjectsWithTag("Player");
            foreach (GameObject player in allplayers)
            {
                if (player.GetComponent<Movement>() != null) player.GetComponent<Movement>().godMode = !player.GetComponent<Movement>().godMode;
            }
        }
    }

    public void FinalMenuActive()
    {
        finalMenuUI.SetActive(true);
        Time.timeScale = 0f;
    }

    public void MainMenu()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("MainMenu");
    }

    public void Restart()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        int scene = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(scene, LoadSceneMode.Single);
    }

    public void NextLevel1()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("Nivel1");
    }
    public void NextLevel2()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("Nivel2");
    }

    public void NextLevel3()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("Nivel3");
    }

    public void NextLevel4()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("Nivel4");
    }

    public void NextLevel5()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("Nivel5");
    }

    public void Credits()
    {
        Time.timeScale = 1f;
        SceneManager.LoadScene("Creditos");
    }

    public void addOne(Movement player)
    {
        factMult += 0.1f;
        playerScore += (int) (100 * factMult);
        cont++;
        players.Add(player);
    }

    public void spawnOne()
    {
        if (cont < 50)
        {
            float maxZ = -9999999f;
            float X = 0;
            //print("Hey");
            foreach (Movement player in players)
            {
                //print("Hey");
                if (player.getZ() > maxZ)
                {
                    X = player.transform.position.x;
                    maxZ = player.getZ();
                }
            }

            float zspawn = maxZ + 1.0f;
            Vector3 spawnPos = new Vector3(X, 1.5f, zspawn);
            Movement spawned = Instantiate(playerPref, spawnPos, Quaternion.identity).GetComponent<Movement>();
            spawned.logic = this;
        }
    }
    public void killOne()
    {
        Movement killed = players[0];
        killed.Die();
    }

    public void removeOne(Movement player)
    {
        factMult -= 0.1f;
        playerScore -= 100;
        if (playerScore < 0) playerScore = 0;
        cont--;
        players.Remove(player);
    }

    public void waveJump()
    {
        float minZ = 1000000f;
        //print("Hey");
        foreach (Movement player in players)
        {
            //print("Hey");
            if (-player.getZ() < minZ) minZ = -player.getZ();
        }

        foreach (Movement player in players)
        {
            player.Jump(minZ);
        }
    }

    public void restartCurrentScene()
    {
        int scene = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(scene, LoadSceneMode.Single);
    }

    public int getCont()
    {
        return cont;
    }
}
